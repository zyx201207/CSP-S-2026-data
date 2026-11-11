#include <bits/stdc++.h>
using namespace std;
int n,m,A[200005],a[200005][35],cnt[35],ans=-1;
bool ban[200005];
void to2(int num,int idx){
	int now=0;
	while(num){
		a[idx][now]=num%2;
		cnt[now]+=num%2;
		num/=2;
		now++;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++){
	    cin>>A[i];
	    to2(A[i],i);
	}
	for (int i=31;i>=0;i--){
		if (cnt[i]>=m){
			for (int j=0;j<n;j++){
				if ((!a[j][i])&&ban[j]!=1){
				    ban[j]=1;
				    for (int k=i;k>=0;k--){
						if (a[j][k])
						  cnt[k]--;
					}
				}
			}
		}
	}
	int cnt2=0;
	for (int i=0;i<n;i++){
		if (!ban[i]){
			if (ans==-1)
			  ans=A[i];
			ans&=A[i];
			cnt2++;
		}
		if (cnt2==m)
		  break;
	}
	cout<<ans;
	return 0;
}
