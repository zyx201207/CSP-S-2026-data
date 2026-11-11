#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m;
int a[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int s=0,ans=0,cnt=0;
		for(int j=i;j<n;j++){
			if(a[j]==i+1){
				for(int k=0;k<n;k++){
					if(a[k]==i+1){
						s=k;
						break;
					}
				}
				if(s==0&&a[s]!=i+1)s=j;
				for(int k=s;k<cnt;k++){
					a[k]=0;
				}
				cnt=s;
				a[s]=i+1;
			}
			else{
				a[ans]=a[j];
				cnt++;
			}
			ans++;
		}
		b[i+1]=cnt;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
