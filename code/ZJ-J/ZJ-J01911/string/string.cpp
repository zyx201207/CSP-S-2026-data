#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m[200005],cnt=0;
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>c[i];
	}int i=1,j=n;
	while(i<=j){
		if(c[i]!=c[j]){
			if(m[i]<m[j]){
				cnt+=m[i];
				m[j]-=m[i];
				i++;
			}else if(m[i]>m[j]){
				cnt+=m[j];
				m[i]-=m[j];
				j--;
			}else{
				cnt+=m[j];
				i++;
				j--;
			}
		}else{
			if(m[i]<m[j]){
				m[j]-=m[i];
				i++;
			}else if(m[i]>m[j]){
				m[i]-=m[j];
				j--;
			}else{
				i++;
				j--;
			}
		}
	}cout<<cnt;
	return 0;
}
