#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int t[300005];
int tb[500005];
int ans[300005]={0};

void clr(int a,int b){
	for(int i=a;i<=b;i++){
		t[tb[i]]=0;
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int p=0;
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			p++;
			if(t[a[j]]){
				p=t[a[j]];
				clr(p+1,j-p);
			}
			tb[p]=a[j];
			t[a[j]]=p;
		}
		for(int i=1;i<=p;i++){
			ans[tb[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
