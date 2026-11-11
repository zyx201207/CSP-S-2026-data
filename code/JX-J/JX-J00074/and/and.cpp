#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=0;
	int a[n+5];
	string s[n+5]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int c=a[i];
		while(c>0){
			if(c%2==0){
				if(c==a[i]) s[i]="0";
				else s[i]+="0";
			}
			else{
				if(c==a[i]) s[i]="1";
				else s[i]+="1";
			}
			c/=2;
		}
		cout<<s[i]<<" ";
	}
	while(m){
		int num=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int m=max(s[i].size(),s[j].size()),f=m;
				for(int y=1;y<=f;y++){
					if(s[i][m]!=s[j][m]){
						num++;
						m--;
						}
				}
			}
		if(num>maxn) maxn=num;
		}
	}
	cout<<maxn;
	return 0;
}
