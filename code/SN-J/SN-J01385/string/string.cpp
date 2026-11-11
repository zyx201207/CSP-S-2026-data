#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,b;
	long long n,m;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>m>>a;
		for(long long j=0;j<m;j++){
			b+=a;
		}
	}
	long long cnt=0,minn=1000000005;
	for(long long i=0;i<n;i++){
		cnt=0;
		for(long long j=0;j<n;j++){
			if(b[j]!=b[n-j-1]){
				cnt++;
			}
		}
		if(cnt<minn){
			minn=cnt;
		}
	}
	cout<<minn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

