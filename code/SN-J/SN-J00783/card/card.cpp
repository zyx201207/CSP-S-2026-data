//孙瑞泽	SN-J00783	西安市第八十九中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,num[500005],s[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>num[i]; 
	}
	for(int k=0;k<n;k++){
		for(int i=k;i<n;i++){
			if(s[num[i]]==0){
				s[num[i]]++;
			}else{
				for(int j=num[i];j<n;j++){
					s[j]=0;
				}
			}
		}
		for(int i=k;i<n;i++){
			ans[i]+=s[i];
			s[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
