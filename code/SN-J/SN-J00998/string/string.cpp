#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int len;
	char w;
}a[200005];
long long cnt;
string s;
long long sum;
long long pos;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len;
		cin>>a[i].w;
		cnt+=a[i].len;
	}
	if(cnt%2!=0){
		long long mid=cnt/2;
		for(int i=1;i<=n;i++){
			if(sum+a[i].len<mid){
				sum+=a[i].len;
			}else{
				a[i].len-1;
			}
		}
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].w!=a[r].w){
			if(a[l].len>a[r].len){
				pos+=a[r].len;
				a[l].len-=a[r].len;
				r--;
			}else if(a[l].len==a[r].len){
				pos+=a[r].len;
				l++;
				r--;
			}else{
				pos+=a[l].len;
				a[r].len-=a[l].len;
				l++;
			}
		}else{
			if(a[l].len>a[r].len){
				a[l].len-=a[r].len;
				r--;
			}else if(a[l].len==a[r].len){
				l++;
				r--;
			}else{
				a[r].len-=a[l].len;
				l++;
			}
		}
	}
	cout<<pos;
	return 0;
}
