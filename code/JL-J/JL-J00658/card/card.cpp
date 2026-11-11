#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,a[N],card_pos,times;
int main(){
	long long count=0;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[j]==a[i]){
				times++;
				if(times>=1){
					card_pos=j;
					break;
				}
			}
		}
		for(int j=card_pos;j<n;j++){
			count=0;
			for(int k=0;k<m;k++){
				if(a[j]==k)count++;
				break;
			}
			cout<<count<<endl;
		}
	}
}
