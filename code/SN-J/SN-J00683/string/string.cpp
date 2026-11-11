//chenjingxuan xianshidibashijiuzhongxue SN-J00683
#include<bits/stdc++.h>
using namespace std;
char w;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum;
	int n,a = 0,m = 0,l = 0,mistake = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a >> w;
		sum += a;
		for(int j = 1;j <= a;j++){
			s+=w;
		}
	}
	
	for(int i = 0;i<s.size()/2;i++){
//		cout << "ir ";
		if(s.size() % 2){
//			cout << "[]";
			m = (s.size()+1)/2;
			int q = 0,p = s.size()-1;
			for(int j = 1;j <= s.size()/2;j++){
//				cout << " lsls ";
				if(s[q] != s[p] && q < m && p > m){mistake++;}
				cout << mistake << ' ' << q << " " << p << " psps  ";

				q++,p--;
			
		}
	}
		else{
//			cout << "[]";
			m = s.size()/2;
			int q = 0,p = s.size()-1;
			for(int j = 1;j <= s.size()/2;j++){
//				cout << " lsls ";
				if(s[q] != s[p] && q <= m && p >= m){mistake++;
//				cout << "uyuy";
				}
//				cout << mistake << ' ' << q << " " << p << " psps  ";
				q++,p--;
		}
	}
	cout << mistake;
	return 0;
}
}

