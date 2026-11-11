#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
struct node{
	int cnt;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].c;
		sum+=a[i].cnt;
	}
	long long i=1,j=n,tmp=0,ans=0;
	while(i<j&&tmp<sum/2){
		if(a[i].c==a[j].c){
			if(a[i].cnt>=a[j].cnt){
				tmp+=a[j].cnt;
				a[i].cnt-=a[j].cnt;
				j--;
			}else{
				tmp+=a[i].cnt;
				a[j].cnt-=a[i].cnt;
				i++;
			}
		}else{
			if(a[i].cnt>=a[j].cnt){
				tmp+=a[j].cnt;
				ans+=a[j].cnt;
				a[i].cnt-=a[j].cnt;
				j--;
			}else{
				tmp+=a[i].cnt;
				ans+=a[i].cnt;
				a[j].cnt-=a[i].cnt;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
