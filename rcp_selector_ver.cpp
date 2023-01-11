#include <stdio.h>
#include <stdexcept>

int main(void){
	int playerCount;
	
	int physicals[3][3] = {		//�� [����, ����, ��]  |  �� [���, �̱�, ��] 
		{0, 2, 1},
		{1, 0, 2},
		{2, 1, 0}
	};
	int result[3] = {0, 0, 0};
	
	printf("���ӿ� ������ �÷��̾� �ο���: ");
	scanf("%d", &playerCount);
	if(playerCount <= 1){
		printf("2�� ���ϴ� ������ ������ �� �����ϴ�.\n");
		return 1;
	}
	
	int playerToStatus[playerCount];	//playerId => statusId
	int tmpCount = 0;
	int tmpValue = 0;
	while(tmpCount < playerCount){
		printf("%d�� ����� ���� (1: ����, 2:����, 3: ��) : ", (tmpCount + 1));
		scanf("%d", &tmpValue);
		if(tmpValue < 1 || tmpValue > 3){
			printf("������ 1: ����, 2:����, 3: ��\n");
			continue;
		}
		
		playerToStatus[tmpCount] = tmpValue;
		result[tmpValue-1] += 1;
		++tmpCount;
	}
	
	printf("\n��������������������������������������������\n\n"); 	//����� ����� ���� ��
	
	/*
	 * 1. ���� ������ �������� Ȯ���� 
	 * ���: ���� �и� �� ��� (����, ����, �� �� ���)
	 * ����: ����, ����, �� | ����, ����, ���� 
	 */ 
	for(int i = 0; i < 3; i ++){
		if(result[i] <= 1){ //1���̸� �н��� 
			continue;
		}
		if(result[physicals[i][1]] > 0 || result[physicals[i][2]] > 0){
			continue;
		}
		printf("���� ������ �Ұ����մϴ�.\n");
		return 0;
	}
	
	/**
	 * End. ���� ���и� �����ؾ���
	 *
	 * �˻� �ܰ�
	 * 2-1. ������ Ȯ���ؾ��� (����: ������ ���� �迭�� �˻��ؼ� �޸𸮸� ȿ�������� ����ؾ���)
	 * 2-2. �̰����� �̰�ٰ� ���ID ����ϰ� ���� ������ �˻��ؾ��� 
	 */
	int inserted = 0;
	for(int i = 0; i < playerCount; i ++){
		int statId = playerToStatus[i] - 1;
		int rootLoseId = physicals[statId][2]; //���� �� 
		if(result[rootLoseId] > 1){
			continue;
		}
		int rootWinId = physicals[statId][1];  //���� �� 
		if(result[rootWinId] > 0){
			printf("%d�� ����ڰ� �̰���ϴ�.\n", (i + 1));
			inserted++;
		}
	}
	if(inserted == 0){
		printf("���ڰ� �����ϴ�.");
	}
	return 0;
}
