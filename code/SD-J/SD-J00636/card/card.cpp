#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int b[N];
int flag[N];
int cnt;
int num[N];
int sta[N],top;
int t[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		b[i]=flag[a[i]];
//		flag[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=top;k++){
				if(sta[k]==a[j]){
					top=k-1;
					break;
				}
			}
			sta[++top]=a[j];
		}
		for(int j=1;j<=top;j++){
			num[sta[j]]++;
		}
//		top=0;
//		for(int j=i;j<=n;j++){
//			if(b[j]>=i){
//				while(sta[top]!=b[j])
//			}
//			else{
//				sta[++top]=j;
//			}
//			cout<<top<<' ';
//		}
//		cout<<endl;
//		for(int j=1;j<=top;j++){
//			cout<<sta[j]<<' ';
//			num[a[sta[j]]]++;
//		}
//		//for(int j=i+1;j<=n;j++)num[a[j]]++;
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<num[i]<<' ';
	return 0;
}
/*
4 3
1 2 1 3
*/
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
