#include <iostream>
#include <time.h>

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = { };
	int Bingo = 0;


	// 1~25 숫자 배열 생성
	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
	}

	// 셔플
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	while (true)
	{
		system("cls");
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					std::cout << '*' << "\t";

				else
					std::cout << iNumber[i * 5 + j] << "\t";
			}

			std::cout << std::endl;
		}
		std::cout << "빙고 수 : " << Bingo << std::endl;
		std::cout << " 숫자를 입력하세요.(0 : 종료) : ";
		int i_nput = 0;
		std::cin >> i_nput;
		//예외처리
		if (i_nput == 0) break;

		else if (i_nput < 1 || i_nput > 25)
			continue;

		//중복체크
		bool bAcc = true;

		for (int i = 0; i < 25; i++)
		{
			if (iNumber[i] == i_nput)
			{
				bAcc = false;
				iNumber[i] = INT_MAX;
				break;
			}
		}

		int iCheck1 = 0, iCheck2 = 0 , iCheck3 = 0, iCheck4 = 0;

		for (int i = 0; i < 5; i++)
		{

			iCheck1 = iCheck2 = iCheck3 = iCheck4 =0;
			//가로 빙고 검사
			for (int j = 0; j < 5; j++)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					++iCheck1;
			}

			if (iCheck1 == 5) 
				++Bingo;
				
			//세로 빙고 검사
			for (int j = 0; j < 5; j++)
			{
				if (iNumber[i * 5 + 5 * j] == INT_MAX)
					++iCheck2;
			}

			if (iCheck2 == 5)
				++Bingo;

			//위에서 아래 대각선 빙고 검사
			if (i * 5 == 0) {
				for (int j = 0; j < 5; j++)
				{
					if (iNumber[i * 5 + 6 * j] == INT_MAX)
						++iCheck3;
				}

				if (iCheck3 == 5)
					++Bingo;
			}
			
			//아래에서 위 대각선 빙고 검사
			if (i * 5 == 20) {
				for (int j = 0; j < 5; j++)
				{
					if (iNumber[i * 5 - 4 * j] == INT_MAX)
						++iCheck4;
				}

				if (iCheck4 == 5)
					++Bingo;
			}
		}

		if (bAcc) continue;

	}

	return 0;
}