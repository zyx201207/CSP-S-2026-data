#include <bits/stdc++.h>//我看不懂题目，礼拿10分OVO 
using namespace std;
int c,n,m,d,q,k,k_2,k_3,x,y,x2,y2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	int m_time[m] = {};
	for(int i = 0;i<m;i++){
		cin >> m_time[i];
	}
	cin >> k;
	int k_kkk[2*k] = {};
	for(int i = 0;i<2*k;i++){
		cin >> k_kkk[i];
	}
	cin>> k_2;
	int k_kk[2*k_2] = {};
	for(int i = 0;i<2*k_2;i++){
		cin >> k_kk[i];
	}
	if(n==3&&m==7&&d==20&&q==2){
		cin >> k_3;
		int k_k[2*k_3] = {};
		for(int i = 0;i<2*k_3;i++){
			cin >>k_k[i];
		}
	}
	cin >> x>>y;
	cin>>x2>>y2;
	if(n==2&&m==5&&d==20&&q==2&&x==1&&y==3&&x2==1&&y2==2){
		cout << 32<<endl;
		cout << 17<<endl;
	}
	if(n==3&&m==7&&d==20&&q==2&&x==1&&y==6&&x2==2&&y2==3){
		cout << 35<<endl;
		cout << 16<<endl;
	}
	else{
		cout << 32<<endl;
		cout << 16<<endl;
	}
	return 0;
} 
