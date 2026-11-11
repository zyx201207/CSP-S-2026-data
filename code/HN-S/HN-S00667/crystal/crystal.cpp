#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	
	freopen("crystal.out","w",stdout);
	
	int n,m,s[100005],cnt = 0;
	
	cout<<"请输入水晶数量与操作次数："<<endl;
	
	cin>>n>>m;
	
	cout<<"请输入"<<n<<"颗水晶的能量值：";
	for(int i = 1; i <= n; i++){
		cin>>s[i];
	}         
	
	for(int i = 1; i <= n; i++){
		s[1] += 4;
		
		cnt++;
		
		s[2] += 4;
		
		cnt++;
		
		s[3] += 4;
		
		cnt++;
		
		break;
	}
	cout<<"操作次数为："<<cnt<<endl;
	return 0;
}
