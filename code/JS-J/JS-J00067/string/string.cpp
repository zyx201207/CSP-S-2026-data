#include <bits/stdc++.h>
using namespace std;
long long t,sum12,sum1,sum2,cnt;
char c;
string v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>c;
		sum12+=t;
		for(int j=1;j<=t;j++){
			v+=c;
		}
	}
	
	if(sum12%2==0) sum1=sum12/2-1,sum2=sum1+1;
	else sum1=sum12/2,sum2=sum12/2;
	
	for(int i=0,j=sum12-1;i<=sum1&&j>=sum2;i++,j--){
			if(v[i]!=v[j]){
				cnt++;
			}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
