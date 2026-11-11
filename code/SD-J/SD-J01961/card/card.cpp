#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005],zm[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int fs=1;fs<=n;fs++){
		int idx=1;
		for(int i=fs;i<=n;i++){
			bool f=0;
			if(i==fs) zm[idx]=a[i];
			else{
				for(int p=1;p<=idx;p++){
					if(zm[p]==a[i]){
						f=1;
						for(int q=p+1;q<=idx;q++){
							zm[q]=0;
						}
						idx=p;
						zm[idx]=a[i];
					}
				}
			}
			if(!f) zm[idx]=a[i];
			idx++;
		}
		for(int i=1;i<idx;i++){
			ans[zm[i]]++;
		}
		memset(zm,0,idx);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
