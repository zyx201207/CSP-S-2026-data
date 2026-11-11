#include<bits/stdc++.h>
using namespace std;
int s[500005];
int t[500005];
int bj[3005];
struct node{
	int l,r;
}x[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			x[j].r=0;
			x[j].l=0;
			bj[j]=0;
		}
		for(int j=i;j<=n;j++){
			bj[s[j]]++;
			x[s[j]].l=x[s[j]].r;
			x[s[j]].r=j;
			if((x[s[j]].r!=0)&&(x[s[j]].l!=0)){
				for(int k=x[s[j]].l+1;k<x[s[j]].r;k++){
					bj[s[k]]--;
					x[s[k]].r=0;
//					cout<<bj[k]<<" ";
					
				}
				bj[x[s[j]].l]--;
//				x[x[s[j]].l].r=0;
//				cout<<endl;
			}
			
		}
		for(int j=1;j<=n;j++){
			if(bj[j]>0){
				t[j]++;
			}
		}
	}
	for(int j=1;j<=m;j++){
		cout<<t[j]<<" ";
			
	}
	return 0;
}