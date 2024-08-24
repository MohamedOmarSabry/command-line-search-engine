#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <fstream>
#include<algorithm>
#include <cctype>
#include <string>
using namespace std;

void SaveN(map<string, vector <int>>& K, vector<vector<string>>&M)
{
	map<string, vector <int>>::iterator IT;
	//vector<vector <string>>::iterator IT2;
	vector <string>::iterator IT3;
	ofstream X;
	X.open("WebIMP.csv");
	for (int i=0;i<M.size();i++)
	{
		IT = K.find(M[i][0]);
		X << IT->first << "," << IT->second[0] << "," << IT->second[1] << endl;
	}
	X.close();
}

void FinalRank(map<float, int>& Q, vector<vector<string>>&M)
{
	vector<vector<string>>S;
	map<float, int>::iterator IT3;
	//map<float, int>::iterator IT4;
	//int i = 29;
	IT3 = Q.end();
	IT3--;
	for (IT3; IT3 != Q.begin()--; IT3--)
	{
		///cout << "Swapping: " << IT3->second << " with: " << i << endl;
		//M[IT3->second].swap(M[i]);
		S.push_back(M[IT3->second]);
		//M[IT3->second].swap(M[i]);
		//cout << M[i][0] << endl;
		//i--;
		//cout << "i--" << endl;
	}
	S.push_back(M[IT3->second]);
	M = S;
}

void SCSF(map<string, vector <int>>& K, map<string, float>& F, map<float,int>& Q)
{
	map<string, vector <int>>::iterator IT1;
	map<string, float>::iterator IT4;
	map<float, int>::iterator IT3;
	for (IT4 = F.begin(); IT4 != F.end(); IT4++)
	{
		IT1 = K.find(IT4->first);
		Q.emplace(IT4->second, IT1->second[0]);
	}
	
}

void PrintSC(map<float, int>&Q)
{
	map<float, int>::iterator IT3;
	for (IT3 = Q.begin(); IT3 != Q.end(); IT3++)
	{
		cout << IT3->first << " " << IT3->second << endl;
	}
}

void SCORE(map<string, vector <int>>& K, map<int, float>& M, map<string, vector <int>>& J, map<string, float>& F)
{
	map<string, vector <int>>::iterator IT1;
	map<int, float>::iterator IT2;
	map<string, vector <int>>::iterator IT3;
	map<string, float>::iterator IT4;
	for (IT1 = K.begin(); IT1 != K.end(); IT1++)
	{
		float Score = 0;
		IT1->second[0];
		float x = (float) 1 - (((float)0.1 * J[IT1->first][0]) / ((float)1 + (float)0.1 * J[IT1->first][0]));
		float y = M[IT1->second[0]] + (((float)0.1 * J[IT1->first][0]) / ((float)1 + (float)0.1 * J[IT1->first][0])) * J[IT1->first][1];
		//cout << "X: " << x << " " << "Y: " << y << endl;
		Score = ((float)0.4 * M[IT1->second[0]]) +( (x*y)* (float)0.4);
		//cout << IT1->second[0]<<" " << Score << endl;
		F.emplace(IT1->first, Score);
	}
}

void PrintScore(map<string, float>& F)
{
	map<string, float>::iterator IT;
	for (IT = F.begin(); IT != F.end(); IT++)
	{
		cout << IT->first << " " << IT->second << endl;
	}

}

void LoadWebI(vector<vector<string>>& M)
{
	vector<vector<string>> Main_V2;
	ifstream f2;
	f2.open("WebIMP.csv");
	string line;
	vector<string> TempV2;
	while (getline(f2, line))
	{
		string temp;
		for (int i = 0; i < line.size(); i++)
		{
			//cout << line[i];
			if (line[i] != ',' && line[i] != '\n')
			{
				temp.push_back(line[i]);
				//cout << "I";
			}
			else
			{
				TempV2.push_back(temp);
				temp = "";
				//cout << "K";
			}

			if (i + 1 == line.size())
			{
				TempV2.push_back(temp);
				//cout << "J";
				temp = "";
			}
		}
		//cout << endl;
		/*for (int i = 0; i < TempV2.size(); i++)
		{
			cout << TempV2[i] << '\t';
		}*/
		//cout << endl;
		Main_V2.push_back(TempV2);
		TempV2.clear();
	}
	f2.close();
	M = Main_V2;
	//for (int i = 0; i < 30; i++)
	//{
	//	for (int j = 0; j < Main_V[i].size(); j++)
	//	{
	//		cout << Main_V[i][j] << '\t';
	//		//cout << "AMONG";
	//	}
	//	cout << endl;
	//	//cout << "Ussy";
	//}

}

void LoadWebIM(vector<vector<string>>& S, map<string,vector <int>>& K)
{
	map<string, int>::iterator IT;
	vector<int> M;
	for (int i = 0; i < S.size(); i++)
	{
		//cout << i << " "<<S[i][1]<<" "<< S[i][2]<<endl;
		M.push_back( stoi(S[i][1]));
		M.push_back(stoi(S[i][2]));
		K.emplace(S[i][0], M);
		M.clear();

	}
	//IT = K.find("");
	//K.erase(IT);
}

void LoadWebG(vector<vector<string>>& M)
{
	vector<vector<string>> Main_V2;
	ifstream f2;
	f2.open("WebGraph.csv");
	string line;
	vector<string> TempV2;
	while (getline(f2, line))
	{
		string temp;
		for (int i = 0; i < line.size(); i++)
		{
			//cout << line[i];
			if (line[i] != ','&& line[i] != '\n')
			{
				temp.push_back(line[i]);
				//cout << "I";
			}
			else
			{
				TempV2.push_back(temp);
				temp = "";
				//cout << "K";
			}
			
			if (i+1==line.size())
			{
				TempV2.push_back(temp);
				//cout << "J";
				temp = "";
			}
		}
		//cout << endl;
		//for (int i = 0; i < TempV2.size(); i++)
		//{
			//cout << TempV2[i] << '\t';
		//}
		//cout << endl;
		Main_V2.push_back(TempV2);
		TempV2.clear();
	}
	f2.close();
	M = Main_V2;
	//for (int i = 0; i < 30; i++)
	//{
	//	for (int j = 0; j < Main_V[i].size(); j++)
	//	{
	//		cout << Main_V[i][j] << '\t';
	//		//cout << "AMONG";
	//	}
	//	cout << endl;
	//	//cout << "Ussy";
	//}

}

void LoadWebM(vector<vector<string>>& S, map<string, vector<int>>& K)
{
	map<string, vector<int>>::iterator IT;
	map<string, vector<int>> K2;
	vector<int>M(3);
	for (int i = 0; i < 3; i++)
	{
		M[i] = 0;
	}
	for (int i = 0; i < S.size(); i++)
	{
		M[0] = i;
		M[2] = 2;
		//cout << S[i][0] << " " << M[0]<< " " << M[1]<< " " << M[2] << endl;
		//cout<<":D";
		K2.emplace(S[i][0],M);
		//cout << "D:";
	}
	K = K2;
	//IT = K.find("");
	//K.erase(IT);
}

void PrintWebM(map<string, vector<int>>& K)
{
	map<string, vector<int>>::iterator IT;
	vector<int>::iterator IT2;
	for (IT = K.begin(); IT != K.end(); IT++)
	{
		cout << IT->first << " ";
		for (IT2=IT->second.begin(); IT2!= IT->second.end(); IT2++)
		{
			cout << *IT2 << " " ;
		}
		cout << endl;
			
	}
}

void CalcWebM(vector<vector<string>>& S, map<string, vector<int>>& K, map<int, vector<int>>& J)
{
	//map<string,vector<string>> 
	//i=website index, j=index of outgoing
	map<string, vector<int>>::iterator IT;
	map<int, vector<int>>::iterator IT2;
	vector<int> T;
	for (int i = 0; i < S.size(); i++)
	{
		for (int j = 1; j < S[i].size(); j++)
		{
			IT = K.find(S[i][j]);
			IT->second[1] = IT->second[1] + 1;
			//cout << IT->second[0] << endl;
			T.push_back(i);
			IT2 = J.find(IT->second[0]);
			if (IT2 ==J.end())
			{
				J.emplace(IT->second[0], T);
				T.clear();
			}
			else
			{
				IT2->second.push_back(i);
				T.clear();
			}
			
			

		}
		

	}

}

void PrintPR(map<int, float>& M)
{
	map<int,float>::iterator IT;
	for (IT = M.begin(); IT != M.end(); IT++)
	{
		cout << IT->first << " " << IT->second << endl;
	}
}

void PrintMi(map<int, vector<int>>& M)
{
	map<int, vector<int>>::iterator IT;
	for (IT = M.begin(); IT != M.end(); IT++)
	{
		cout << IT->first << " ";
			for (int i = 0; i < IT->second.size(); i++)
		{
			cout << IT->second[i] << " ";
		}
		cout << endl;
	}
}

void PRinit(map<string, vector<int>>& K, map<int, float>& M)
{
	map<string, vector<int>>::iterator IT;
	for (IT = K.begin(); IT != K.end(); IT++)
	{
		IT->second[0];
		M.emplace(IT->second[0], (float)1 / (float)30);
	}
}

void CalcPR(vector<vector<string>>& S, map<string, vector<int>>& K, map<int, vector<int>>& M,map<int, float>& J)
{
	map<string, vector<int>>::iterator IT1;
	map<int, vector<int>>::iterator IT3;
	//map<int, int>::iterator IT2;
	map<int, float>::iterator IT4;
	for (int i = 0; i < 2; i++)
	{
		for (IT1 = K.begin(); IT1 != K.end(); IT1++)
		{
			float sum = 0;
			//cout <<"Website Index: " << IT1->second[0] << endl;
			IT3 = M.find(IT1->second[0]);
			if (IT3 != M.end())
			{
				for (int k = 0; k < IT3->second.size(); k++)
				{
					IT4 = J.find(IT3->second[k]);
					//cout << "Website Pointing at it: " << IT3->second[k] << endl;
					float PRP = IT4->second;
					float O = PRP / (float)2;
					sum = sum + O;

				}
			}
			IT4 = J.find(IT1->second[0]);
			IT4->second = sum;
			//cout <<"New PR: " << sum << endl;
		}
	}
}

void CapitalizeS(string& S, string &S2)
{
	int l = S[0];
	if (islower(l))
	{
		for (int i = 0; i < S.size(); i++)
		{
			//cout << "L2U" << endl;
			int y = S[i];
			S[i] = toupper(y);
			//cout << S[i] << endl;
		}
	}
	else if (isupper(l))
	{
		for (int i = 0; i < S.size(); i++)
		{
			//cout << "UP2L" << endl;
			int x = S[i];
				S[i]=tolower(x);
			//cout << S[i] << endl;
		}
	}
	l = S2[0];
	//cout << S<<endl;
	if (islower(l))
	{
		for (int i = 0; i < S2.size(); i++)
		{
		//	cout << "L2U" << endl;
			int y = S2[i];
			S2[i] = toupper(y);
			//cout << S2[i] << endl;
		}
	}
	else if (isupper(l))
	{
		for (int i = 0; i < S2.size(); i++)
		{
			//cout << "UP2L" << endl;
			int x = S2[i];
			S2[i] = tolower(x);
			//cout << S2[i] << endl;
		}
	}
	//cout << S2 << endl;
}

void Capitalize(string& S)
{
	cout << S[0] << endl;
	if (islower(S[0]) != 1)
	{
		for (int i = 0; i < S.size(); i++)
		{
			//cout << S[0] << endl;
			cout << "L2U" << endl;
			if (isalpha(S[i]) == 1)
			{
				S[i] = toupper(S[i]);
			}
			//cout << y << endl;
			//cout << S[i] << endl;
		}
	}
	else if(isupper(S[0]) == 1)
	{
		for (int i = 0; i < S.size(); i++)
		{
			//cout << S[0] << endl;
			cout << "UP2L" << endl;
			if (isalpha(S[i]) == 1)
			{
				S[i] = tolower(S[i]);
			}	
			//cout << x << endl;
			//cout << S[i] << endl;
		}
	}
	cout << S << endl;
}

void Capitalize2(string& S)
{
	//cout << S[0] << endl;
	if (islower(S[0]) == 1)
	{
		transform(S.begin(), S.end(), S.begin(), &toupper);
	}
	else
	{
		transform(S.begin(), S.end(), S.begin(), &tolower);
	}
	//cout << S << endl;
}
void PrintI(vector<vector<int>>& I)
{
	for (int i = 0; i < I.size(); i++)
	{
		for (int j = 0; j < I[i].size(); j++)
		{
			cout << I[i][j] << '\t';
		}
		cout << endl;
	}
}

void LoadFiles(vector<vector<string>>& M)
{
	vector<vector<string>> Main_V;
	ifstream f1;
	f1.open("WebKeyword.csv");
	string line;
	vector<string> TempV;
	while (getline(f1, line))
	{
		string temp;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] != ',')
			{
				temp.push_back(line[i]);
				//cout << "I";
			}
			else
			{
				TempV.push_back(temp);
				temp = "";
				//cout << "J";
			}
			
		}
		Main_V.push_back(TempV);
		TempV.clear();
	}
	f1.close();
	M = Main_V;
	//for (int i = 0; i < 30; i++)
	//{
	//	for (int j = 0; j < Main_V[i].size(); j++)
	//	{
	//		cout << Main_V[i][j] << '\t';
	//		//cout << "AMONG";
	//	}
	//	cout << endl;
	//	//cout << "Ussy";
	//}

}

void PrintS(vector<vector<string>>& M)
{
	vector<vector<string>>::iterator IT1;
	vector<string>::iterator IT2;
	for (IT1=M.begin(); IT1!=M.end(); IT1++)
	{
		for (IT2=IT1->begin(); IT2!=IT1->end(); IT2++)
		{
			cout << *IT2 << '\t';
			//cout << "AMONG";
		}
		cout << endl;
		//cout << "Ussy";
	}
}

void ValidateRVAND2(vector<vector<int>>& M)
{
	
	vector<vector<int>> M2;
	int v = M[0].size()+ M[2].size();
	vector<int> M1(v);
	//cout << "Premerge";
	merge(M[0].begin(), M[0].end(), M[2].begin(), M[2].end(),M1.begin());
	//cout << "Merge";
	M2.push_back(M1);
	//cout << "Push";
	v = M[1].size() + M[3].size();
	vector<int> M3(v);
	merge(M[1].begin(), M[1].end(), M[3].begin(), M[3].end(), M3.begin());
	//cout << "Merge2";
	M2.push_back(M3);
	//cout << "Push2"<<endl;
	//PrintI(M2);
	bool x, y = 0;
	int j = 0;
	int i = 0;
	for (i; i < M2[0].size(); i++)
	{
		//cout << "FOR" << endl;
		if (M2[1].size() == 0)
		{
			//cout << "M1 Zero " << endl;
			break;
		}
		//cout << "IF1" << endl;
			j++;
			if (binary_search(M2[1].begin(), M2[1].end(), M2[0][i]) == 0)
			{
				//cout << "IF2" << endl;
				j--;
				//cout << "M21 REMOVE "<<i <<" "<<M2[0][i]<<" "<<j << endl;
				if (binary_search(M2[0].begin(), M2[0].end(), M2[1][j]) == 0)
				{
					//cout << "IF3" << endl;
					//cout << "M20 REMOVE " << j << " " << M2[1][j]<<" " << i << endl;
					M2[0].erase(M2[0].begin() + i);
				}
				M2[1].erase(M2[1].begin() + j);

			}
			else
			{
				//cout << "NO " << i << endl;
			}
			if (i + 1 == M2[0].size())
			{
				if (binary_search(M2[1].begin(), M2[1].end(), M2[0][i]) == 0)
				{
					//cout << "M22 REMOVE " << i << " " << M2[0][i]<< " "<< j << endl;
					if (binary_search(M2[0].begin(), M2[0].end(), M2[1][j]) == 0)
					{
						//cout << "M20 REMOVE " << j << " " << M2[1][j] << " " << i << endl;
						M2[0].erase(M2[0].begin() + i);
					}

					M2[1].erase(M2[1].begin() + j);

				}

			}
			if ((M2[0].size() == 0 && M2[1].size() != 0) || (M2[1].size() == 0 && M2[0].size() != 0))
			{
				if (M2[0].size() == 0 && M2[1].size() != 0)
				{
					while(M2[1].size()!=0)
					{
						M2[1].erase(M2[1].begin());
					}
				}
				else
				{
					while (M2[0].size() != 0)
					{
						M2[0].erase(M2[0].begin());
					}
				}
			}
			
	}
	if (i == M2[0].size() && M2[0].size() != M2[1].size())
	{
		//cout << "Erasing End" << endl;
		while (M2[1].size() != 0)
		{
			M2[1].erase(M2[1].begin());
		}
	}
	//PrintI(M2);
	M = M2;
}

void ValidateDup(vector<vector<int>>& M)
{
	vector<int>::iterator IT;
	for (int i = 0; i < M[0].size(); i++)
	{
		if (M[2].size() == 0)
		{
			//cout << "M2 Zero " << endl;
			break;
		}
		else
		{

			if (binary_search(M[2].begin(), M[2].end(), M[0][i]) == 1)
			{
				IT = find(M[2].begin(), M[2].end(), M[0][i]);
				//cout << "M2 REMOVE " << i << " " << M[0][i] << endl;
				M[2].erase(IT);

			}
			else
			{
				//cout << "NO " << i << endl;
			}

		}
	}
	//PrintI(M);
	for (int i = 0; i < M[1].size(); i++)
	{
		if (M[3].size() == 0)
		{
			break;
		}
		else
		{

			if (binary_search(M[3].begin(), M[3].end(), M[1][i]) == 1)
			{

				//cout << "M3 REMOVE " << i << " " << M[1][i] << endl;

				IT = find(M[3].begin(), M[3].end(), M[1][i]);
				M[3].erase(IT);
			}
			else
			{
				//cout << "NO " << i << endl;
			}
		}

	}
	//PrintI(M);
}

void ValidateDup2(vector<vector<int>>& M)
{
	vector<int>::iterator IT;
	vector<vector<int>> M2;
	int v = M[0].size() + M[2].size();
	vector<int> M1(v);
	//cout << "Premerge";
	merge(M[0].begin(), M[0].end(), M[2].begin(), M[2].end(), M1.begin());
	//cout << "Merge";
	M2.push_back(M1);
	//cout << "Push";
	v = M[1].size() + M[3].size();
	vector<int> M3(v);
	merge(M[1].begin(), M[1].end(), M[3].begin(), M[3].end(), M3.begin());
	//cout << "Merge2";
	M2.push_back(M3);
	//cout << "Push2"<<endl;
	for (int i = 0; i < M2[0].size(); i++)
	{
		if (M2[1].size() == 0)
		{
			//cout << "M2 Zero " << endl;
			break;
		}
		else
		{

			if (binary_search(M2[1].begin(), M2[1].end(), M2[0][i]) == 1)
			{
				IT = find(M2[1].begin(), M2[1].end(), M2[0][i]);
				//cout << "M2 REMOVE " << i << " " << M[0][i] << endl;
				M2[1].erase(IT);

			}
			else
			{
				//cout << "NO " << i << endl;
			}

		}
	}
	M = M2;

}

void SearchQuery2(string Query, map<string, vector<int>>& K, vector<vector<int>>& M)
{
	map<string, vector<int>>::iterator IT2;
	IT2 = K.find(Query);
	if (IT2 == K.end())
	{
		//cout << "No results found for the keyword: "<<Query << endl;
		vector<int> MN;
		M.push_back(MN);
	}
	else
	{
		M.push_back(IT2->second);
	}
}

void SearchPreProcess(string Query, map<string, vector<int>>& K, vector<vector<int>>& M)
{
	if (Query[0] == '"' && Query[Query.size() - 1] == '"')
	{
		//cout << "Double Quotes" << endl;
		//BS1
		string Q1;
		Q1 = Query.substr(1, Query.size() - 2);
		SearchQuery2(Q1, K, M);
	}
	else
	{
		string Q3;
		int Pos;
		Pos = Query.find("AND");
		if (Pos != -1)
		{
			//cout << "AND SEARCH" << endl;
			string Q2 = Query.substr(0, Pos - 1);
			string Q3 = Query.substr(Pos + 4, Query.size() - 1);
			string Q4 = Q2;
			string Q5 = Q3;
			SearchQuery2(Q2, K, M);
			SearchQuery2(Q3, K, M);
			CapitalizeS(Q4, Q5);
			SearchQuery2(Q4, K, M);
			SearchQuery2(Q5, K, M);
			//PrintI(M);
			//cout << "DUP" << endl;
			ValidateDup(M);
			//PrintI(M);
			//cout << "RVAND" << endl;
			ValidateRVAND2(M);
			//PrintI(M);

		}
		else
		{
			//cout << "OR SEARCH" << endl;
			Pos = Query.find("OR");
			if (Pos != -1&&Query[Pos-1]==' ')
			{
				string Q2 = Query.substr(0, Pos - 1);
				string Q3 = Query.substr(Pos + 3, Query.size() - 1);
				string Q4 (Q2);
				string Q5 (Q3);
				SearchQuery2(Q2, K, M);
				SearchQuery2(Q3, K, M);
				CapitalizeS(Q4, Q5);
				//cout << Q4 << endl;
				//cout << Q5 << endl;
				SearchQuery2(Q4, K, M);
				SearchQuery2(Q5, K, M);
				//PrintI(M);
				ValidateDup(M);
				//PrintI(M);
				ValidateDup2(M);
				//PrintI(M);

			}
			else
			{
				//cout << "OR SEARCH2" << endl;
				Pos = Query.find(" ");
				string Q2 = Query.substr(0, Pos);
				string Q3 = Query.substr(Pos + 1, Query.size() - 1);
				string Q4 = Q2;
				string Q5 = Q3;
				SearchQuery2(Q2, K, M);
				SearchQuery2(Q3, K, M);
				CapitalizeS(Q4, Q5);
				SearchQuery2(Q4, K, M);
				SearchQuery2(Q5, K, M);
				//PrintI(M);
				ValidateDup(M);
				//PrintI(M);
				ValidateDup2(M);
				//PrintI(M);

			}
		}
	}

}

void LoadMap(map<string, vector<int>>& K, vector<vector<string>>& M)
{
	map<string, vector<int>>::iterator IT;
	for (int i = 0; i < M.size(); i++)
	{
		for (int j = 1; j < M[i].size(); j++)
		{
			IT = K.find(M[i][j]);
			if (IT==K.end())
			{
				vector<int> V;
				V.push_back(i);
				K.emplace(M[i][j], V);
				V.clear();
			}
			else
			{
				IT->second.push_back(i);
			}
				
		}

	}
	IT = K.find("");
	K.erase(IT);
}

void PrintM(map<string, vector<int>>& M)
{
	map<string, vector<int>>::iterator I;
	for (I = M.begin(); I != M.end(); I++)
	{
		cout << I->first << '\t';
		for (int j = 0; j < I->second.size(); j++)
		{
			cout << I->second[j] << '\t';
		}
		cout << endl;
	}
}

void LoadSR(vector<vector<int>>& I, vector<vector<string>>& M, vector<vector<string>>& S, map<string,vector<int>>&J)
{
	vector<vector<int>> M2;
	map<string, vector<int>>::iterator IT;
	int v= I[0].size();
	vector<int> M1(v);
	if (I.size() > 1)
	{
		v = I[0].size() + I[1].size();
		M1.resize(v);
		merge(I[0].begin(), I[0].end(), I[1].begin(), I[1].end(), M1.begin());
	}
	else
	{
		vector<int> M1(v);
		M1 = I[0];
		//cout << "Premerge";
		
	}
	
	//cout << "Merge";
	/*for (int i = 0; i < I.size(); i++)
	{
		for (int j = 0; j < I[i].size(); j++)
		{
			S.push_back(M[I[i][j]]);
		}


	}*/
	for (int i = 0; i < M1.size(); i++)
	{
		S.push_back(M[M1[i]]);
		IT = J.find(S[i][0]);
		IT->second[0] = IT->second[0] + 1;
	}

}

void PrintSR(vector<vector<string>>& S)
{
	//cout << "Printing Solution: " << endl;
	for (int i = 0; i < S.size(); i++)
	{
		cout << i << "- " << S[i][0] << endl;
	}
}

void OpenSite(vector<vector<string>>& S, int k,map<string, vector<int>>& K)
{
	map<string, vector<int>>::iterator IT;
	if (k >= S.size())
	{
		cout << "Invalid Website selected" << endl;
	}
	else
	{
		IT=K.find(S[k][0]);
		IT->second[1] = IT->second[1] + 1;
		cout << "Viewing " << S[k][0] << endl;
	}
}

int main()
{
	vector<vector<string>> SiteDB;
	LoadFiles(SiteDB);
	//PrintS(SiteDB);
	vector<vector<string>>WebG;
	LoadWebG(WebG);
	//PrintS(WebG);
	map<string, vector<int>> M1;
	map<int,vector<int>> M3;
	LoadWebM(WebG,M1);
	//PrintWebM(M1);
	//cout << endl;
	CalcWebM(WebG, M1,M3);
	//PrintWebM(M1);
	map<int, float> PR;
	PRinit(M1,PR);
	//PrintPR(PR);
	//PrintMi(M3);
	CalcPR(WebG, M1, M3, PR);
	//PrintPR(PR);
	vector<vector<string>> AM;
	LoadWebI(AM);
	//PrintS(AM);
	//cout << endl;
	map<string, vector<int>> AM2;
	LoadWebIM(AM, AM2);
	//PrintWebM(AM2);
	//cout << endl;
	map<string, float> R;
	SCORE(M1, PR, AM2, R);
	//PrintScore(R);
	map<float, int> F;
	SCSF(M1, R, F);
	//PrintSC(F);
	FinalRank(F, SiteDB);
	//PrintS(SiteDB);
	map<string, vector<int>> Klist;
	LoadMap(Klist, SiteDB);
	//PrintM(Klist);
	//string Q = "c++ ALGORITHMS";
	vector<vector<int>>IList;
	//SearchPreProcess(Q, Klist, IList);
	//PrintI(IList);
	vector<vector<string>> SRes;
	//LoadSR(IList, SiteDB, SRes,AM2);
	//PrintSR(SRes);
	//PrintWebM(AM2);

	int x = 1;
	int y = 1;
	int z = 1;
	int Option_1;
	int Option_2;
	int Option_3;
	int WebIndx;
	//string QU;
	//cout << QU << endl;
	string Q;
	//getline(cin, Q);
	for (int i = 1; i != 0;)
	{
		cout << "What would you like to do?" << endl;
		cout << "1. New Search" << endl;
		cout << "2. Exit" << endl;
		cout << "Enter your choice" << endl;
		cin >> Option_1;
		if (Option_1 == 1)
		{
			cout << "Entering New Search" << endl;
			cout << "Please input your search query" << endl;
			SRes.clear();
			IList.clear();
			cin.ignore();
			getline(cin, Q, '\n');
			cout << "Searching for " << Q << endl;
			SearchPreProcess(Q, Klist, IList);
			LoadSR(IList, SiteDB, SRes, AM2);
			for (int j = 1; j != 0;)
			{
				PrintSR(SRes);
				cout << endl;
				cout << "Would you like to: " << endl;
				cout << "1. Choose a Webpage to Open" << endl;
				cout << "2. New Search" << endl;
				cout << "3. Exit" << endl;
				cin >> Option_2;
				if (Option_2 == 1)
				{
					cout << "Please enter the index of the website that you want to open: " << endl;
					cin.clear();
					cin >> WebIndx;
					OpenSite(SRes, WebIndx, AM2);
					for (int z = 1; z != 0;)
					{
						cout << "Would you like to: " << endl;
						cout << "1. Go back to search results" << endl;
						cout << "2. New Search" << endl;
						cout << "3. Exit" << endl;
						cin >> Option_3;
						if (Option_3 == 1)
						{
							z = 0;
						}
						else if (Option_3 == 2)
						{
							z = 0;
							j = 0;
						}
						else if (Option_3 == 3)
						{
							SaveN(AM2, AM);
							exit(0);
						}
						else
						{
							z++;
						}
					}
				}
				else if(Option_2 == 2)
				{
					j = 0;
				}
				else if (Option_2 == 3)
				{
					exit(0);
				}
				else
				{
					j++;
				}
				
			}
		}
		else if (Option_1 == 2)
		{
			cout << "Exiting Search Engine" << endl;
			//SaveN(AM2, AM);
			i = 0;
			exit(0);
		}
		else
		{
			cout << "Invalid Input" << endl;
				i++;
		}
			
	}
		
	
	



}