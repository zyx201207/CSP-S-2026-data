#include<bits/stdc++.h>
using namespace std;
int n,a[200200],b[200200],i,j,ans,jishu,forever;
char zimu;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		cin>>zimu;
		forever=jishu;
		for(j=jishu;j<=forever+a[i]-1;j++){
			b[j]=zimu;
			jishu++;
		}
		
	}
	for(i=0;i<=(jishu-2)/2;i++){
			if(b[i]==b[jishu-i-1]){
				continue;
			}
			else
				ans++;
		}
		
	cout<<ans;
	return 0;
	}

