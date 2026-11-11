#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],q[200005];
char c[200005];
const int N=1145145;
int num,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(c[i]==c[j]){
				num++;
			}
		}
	}
	if(num==n-1){
		cout<<"0";
		return 0;
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==b[1]){
			a[i]=N;
			return 0;
		}
		if(a[i]==b[2]){
			cout<<a[i];
			return 0;
		}
	}
	return 0;
}

