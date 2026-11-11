#include<bits/stdc++.h>
using namespace std;
int a[500010];//a[i]表示第i个的组别 
int b[300010];//b[i]表示第i个组别的末位元素下标 
int c[500010];//指针。指向下一个组队 
int ans[500010];
int h[500010];//差分
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	}
	int last=0;
	for(int i=1;i<=n;i++){
		if(b[a[i]]!=i){
			for(int j=last;j<i;j++){
				c[j]=i;
			}
			last=i;
		}
		
	}
	for(int j=last;j<=n;j++){
		c[j]=n+1;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(1){
			if(b[a[j]]!=j){
				ans[a[j]]++;
				j=b[a[j]]+1;
			}else{
				h[j]++;
				h[c[j]]--;
				j=c[j];
			}
			if(j>=n+1)break;
		}
	}
	for(int i=1;i<=n;i++){
		h[i]+=h[i-1];
		ans[a[i]]+=h[i];
	}
	for(int i=1;i<m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<ans[m];
	cout<<endl;
	return 0;
}

