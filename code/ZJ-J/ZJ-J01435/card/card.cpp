#include<bits/stdc++.h>
using namespace std;
int cmp[500500];
int sum[500500];
int a[500500];
int t[500500];
int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int top=0;
	for(int i=1;i<=n;i++){
		t[500500]={0};
		top=0;
		for(int j=i;j<=n;j++){
			cmp[top]=a[j];
			t[cmp[top]]++;
			if(t[cmp[top]]==2){
				t[cmp[top]]=0;
				for(int k=top-1;k>=0;k--){
					if(cmp[k]==cmp[top]){
						top=k;
					}
				}
			}
			else{
				top++;
			}
		}
		for(int j=0;j<=top;j++){
			sum[cmp[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
