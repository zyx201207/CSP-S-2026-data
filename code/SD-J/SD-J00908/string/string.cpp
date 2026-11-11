#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
long long len;
char c[200005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long cnt=0,i=1,j=n,syi=a[1],syj=a[n];
	while(1){
		if(i>=j){
			break;
		}
		if(c[i]!=c[j]){
			if(syi>syj){
				cnt+=syj;
				syi-=syj;
				j--;
				syj=a[j];
			}else if(syi<syj){
				cnt+=syi;
				syj-=syi;
				i++;
				syi=a[i];
			}else{
				cnt+=syi;
				i++;
				j--;
				syi=a[i];
				syj=a[j]; 
			}
		}else{
			if(syi>syj){
				syi-=syj;
				j--;
				syj=a[j];
			}else if(syi<syj){
				syj-=syi;
				i++;
				syi=a[i];
			}else{
				i++;
				j--;
				syi=a[i];
				syj=a[j];
			}
		}
	}
	cout<<cnt;
	return 0;
}

