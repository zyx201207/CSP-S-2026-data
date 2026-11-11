#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	
	int m1[m+2];
	int n1[m+4];
	int n2[m+4];
	for(int i=1;i<=m;i++){
		cin>>m1[i];
		n1[i]=999;
		n2[i]=999;
		}
	for(int i=1;i<=2;i++){
		int a;
		cin>>a;
		for(int j=1;j<=a;j++){
			int s;
			cin>>s;
			if(i==1){
				cin>>n1[s];
				}
			else{
				cin>>n2[s];
				}
			}
	}
	while(q--){
		int ans=0;
		int begin,end;
		cin>>begin>>end;
		ans+=m1[begin];
		ans+=m1[end];
		int cnt=0;
		for(int i=begin;i<=end;i++){
			int min1;
			min1=min(n1[i],n2[i]);
			if(i==begin&&min1==n1[i])cnt=1;
			else if(i==begin&&min1==n2[i])cnt=2;
			if(min1==n1[i]&&cnt==1)ans+=min1;
			else if(min1==n2[i]&&cnt==2)ans+=min1;
			else {
				if(min1==n1[i]&&cnt==2){
					if(min1+n2[i-1]<=n2[i]||n2[i]==999){
						ans+=min1+n2[i-1];
						cnt=1;
						}
					else {
						ans+=n2[i];
						}
					}
				else if(min1==n2[i]&&cnt==1){
					if(min1+n1[i-1]<=n1[i]||n1[i]==999){
						ans+=min1+n1[i-1];
						cnt=2;
						}
					else{
						ans+=n1[i];}
					}
				}
			}
		cout<<ans<<endl;
		}
	
	return 0;
}


