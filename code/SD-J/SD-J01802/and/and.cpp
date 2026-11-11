#include <bits/stdc++.h>
using namespace std;
int n,m,ansmax,b,cinclock,countclock,a[200005];
string b1;
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and,in","w",stdout);
	cin>>n>>m;
	vector<string>vec(n+5);
	vector<string>vecans(n+10);
	if(m!=1){
		while(b!=0)
			b1+=b%2;
			b/=2;
		}
		int i=0;
	
			
		if(m==n){
			for(int i=0;i<=n;i++){
				for(int j=0;j<=m;j++){
				if(vec[i][j]=vec[i+1][j]&&vec[i][j]==1){
					vecans[i]+='1';
				}
				else{
					vecans[i]='0';
				}
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>b;
			if(b>=ansmax){
				ansmax=b;
			}
		}
	}
		cout<<ansmax;
		return 0;
}
