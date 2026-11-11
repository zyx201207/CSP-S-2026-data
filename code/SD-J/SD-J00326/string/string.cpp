#include <bits/stdc++.h>
using namespace std;

struct h{
	long long a;
	char c;
};

h b[20005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].a;
		cin>>b[i].c;
	}
	long long cnt=0;
	for(int i=1;i<=n/2;i++){
		if(b[i].c==b[n-i+1].c){
			if(b[i].a==b[n-1+i].a){
				break;
			}
			else if(i==n/2){
				n++;
			}
			else cnt+=abs(b[i].a-b[n-i+1].a);
		}
		else cnt+=max(b[i].a,b[n-1+1].a);
	}
	cout<<cnt;
	return 0;
}
	
