#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],wk[N],sum[N],pos[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=n;i>=1;i--){
		if(pos[a[i]]!=0){
			int tmp=cnt;
			cnt=pos[a[i]];
			for(int i=cnt+1;i<=tmp;i++){
				pos[wk[i]]=0;
				wk[i]=0;
			}
//			for(int j=1;j<=10;j++) cout<<pos[j]<<" ";
//			cout<<a[i]<<'a'<<cnt<<endl;
//			for(int j=1;j<=cnt;j++){
//				cout<<wk[j]<<" ";
//			}
//			cout<<endl;
			for(int j=1;j<=cnt;j++){
				sum[wk[j]]++;
			} 
			
//			for(int j=1;j<=m;j++){
//				cout<<sum[j]<<" ";
//			}cout<<endl;
			continue;
		}
		wk[++cnt]=a[i];
		pos[a[i]]=cnt;
		for(int i=1;i<=cnt;i++){
			sum[wk[i]]++;
		} 
//		for(int i=1;i<=m;i++){
//			cout<<sum[i]<<" ";
//		} 
//		cout<<endl;
//		for(int i=1;i<=cnt;i++){
//			cout<<wk[i]<<" ";
//		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	
	return 0;
} 








