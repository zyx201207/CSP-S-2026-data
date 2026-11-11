#include<bits/stdc++.h>
using namespace std;
long long nge,mge,cnt[500005],ans[500005],r,queue[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>nge>>mge;
	for(int i=1;i<=nge;i++){
		cin>>ans[i];
	}
//	for(int i=1;i<=nge;i++){
//		r=2;
//		for(int j=i;j<=nge;j++){
//			for(int k=1;k<r;k++){
//				if(queue[k]==ans[j]){
//					r=k+1;
//					break;
//				}
//			}
//			queue[r++]=ans[j];
//		}
//		for(int i=1;i<r;i++){
//			cnt[queue[i]]++;
//		}
//	}
	for(int i=1;i<=mge;i++){
		cout<<0<<" ";
	}
	return 0;
} 
