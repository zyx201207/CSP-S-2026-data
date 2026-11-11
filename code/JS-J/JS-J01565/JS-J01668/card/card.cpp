#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],s[300005],as[300005];
vector<int> p;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
			memset(s,0,sizeof(s));
			for(int j=i;j<=n;j++){
				//s[a[j]]++;
				if(s[a[j]]){
					for(int k=s[a[j]];k<j;k++){
						s[a[k]]=0;
					}
				}
				s[a[j]]=j;
			}
			
			for(int j=1;j<=m;j++){
				//cout<<s[j]<<" ";
				if(s[j]){
					as[j]++;
				}
			}
		//	cout<<endl;
	}
	for(int i=1;i<=m;i++){
			cout<<as[i]<<" ";
	}
	
	return 0;
}
