#include<bits/stdc++.h>
#define int long long
using namespace std;
int arr[500005]={};
int brr[300005]={};
int t=0;
int crr[500005]={};
int drr[300005]={};
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=false;
			for(int x=1;x<=t;x++){
				if(arr[j]==crr[x]){
					t=x;
					flag=true;
					break;
				}
			}
			if(flag==false){
				t++;
				crr[t]=arr[j];
			}
		}
		for(int j=1;j<=t;j++){
			if(drr[crr[j]]==0){
				drr[crr[j]]=1;
				brr[crr[j]]++;
			}
		}
		memset(drr,0,sizeof(drr));
		t=0;
	}
	for(int i=1;i<=m;i++){
		cout<<brr[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
