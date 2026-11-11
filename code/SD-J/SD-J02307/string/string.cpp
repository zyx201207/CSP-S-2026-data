#include<iostream>
using namespace std;
const int N=2e5+10;
int n;
int a[N];
char c[N];
long long cnt;
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1;
	int r=n;
	while(1){
		if(l>r){
			break;
		}
		if(c[l]!=c[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				cnt+=a[l];
				l++;
			}
			else{
				a[l]-=a[r];
				cnt+=a[r];
				r--;
			}
		}
		else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
