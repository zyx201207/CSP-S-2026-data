#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=5e5+10;
int n,m,a[N],s[N],ans,cnt,t,q[N]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m;j++){
			bool flag;
			for(int p=1;p<=cnt;p++){
				if(s[p]==a[j]){
					flag=0;
				}
			}
			if(flag==1){
				s[cnt++]=a[j];
			}
		}
		for(int j=1;j<=cnt;j++){
			q[s[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<q[i];
	}
	return 0;
}
