#include <stdio.h>
#include <stdexcept>

int main(void){
	int playerCount;
	
	int physicals[3][3] = {		//행 [가위, 바위, 보]  |  열 [비김, 이김, 짐] 
		{0, 2, 1},
		{1, 0, 2},
		{2, 1, 0}
	};
	int result[3] = {0, 0, 0};
	
	printf("게임에 참가할 플레이어 인원수: ");
	scanf("%d", &playerCount);
	if(playerCount <= 1){
		printf("2명 이하는 게임을 진행할 수 없습니다.\n");
		return 1;
	}
	
	int playerToStatus[playerCount];	//playerId => statusId
	int tmpCount = 0;
	int tmpValue = 0;
	while(tmpCount < playerCount){
		printf("%d번 사용자 선택 (1: 가위, 2:바위, 3: 보) : ", (tmpCount + 1));
		scanf("%d", &tmpValue);
		if(tmpValue < 1 || tmpValue > 3){
			printf("선택은 1: 가위, 2:바위, 3: 보\n");
			continue;
		}
		
		playerToStatus[tmpCount] = tmpValue;
		result[tmpValue-1] += 1;
		++tmpCount;
	}
	
	printf("\n――――――――――――――――――――――\n\n"); 	//결과값 출력을 위한 선
	
	/*
	 * 1. 게임 진행이 가능한지 확인함 
	 * 방식: 같은 패를 낸 경우 (가위, 가위, 보 일 경우)
	 * 예외: 가위, 가위, 보 | 가위, 가위, 바위 
	 */ 
	for(int i = 0; i < 3; i ++){
		if(result[i] <= 1){ //1명이면 패스함 
			continue;
		}
		if(result[physicals[i][1]] > 0 || result[physicals[i][2]] > 0){
			continue;
		}
		printf("게임 진행이 불가능합니다.\n");
		return 0;
	}
	
	/**
	 * End. 게임 승패를 구분해야함
	 *
	 * 검사 단계
	 * 2-1. 졌는지 확인해야함 (이유: 졌으면 다음 배열을 검사해서 메모리를 효율적으로 사용해야함)
	 * 2-2. 이겼으면 이겼다고 멤버ID 출력하고 다음 참가자 검사해야함 
	 */
	int inserted = 0;
	for(int i = 0; i < playerCount; i ++){
		int statId = playerToStatus[i] - 1;
		int rootLoseId = physicals[statId][2]; //약한 패 
		if(result[rootLoseId] > 1){
			continue;
		}
		int rootWinId = physicals[statId][1];  //강한 패 
		if(result[rootWinId] > 0){
			printf("%d번 사용자가 이겼습니다.\n", (i + 1));
			inserted++;
		}
	}
	if(inserted == 0){
		printf("승자가 없습니다.");
	}
	return 0;
}
