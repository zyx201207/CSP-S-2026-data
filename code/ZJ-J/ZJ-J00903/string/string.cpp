#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,num,sum,ans;
struct node{
	int front,end;
	char a;
}p[200005];
int jd[500005];
char mp[5000000];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num>>p[i].a;
		p[i].front=sum+1;
		sum+=num;
		p[i].end=sum;
		for(int j=p[i].front;j<=p[i].end;j++){
			mp[j]=p[i].a;
		}
	}
	for(int i=1;i<=(sum/2+1);i++){
		if(mp[i]!=mp[sum-i+1]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

