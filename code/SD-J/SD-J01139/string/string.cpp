#include<bits/stdc++.h>
using namespace std;
int n;
long long sum,ans,cnt=1;

char cc[10000010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		scanf("%d %c",&x,&c);
		for(long long j=sum+1;j<=x+sum;j++){
			cc[j]=c;
		}
		sum+=x;
	}
	if(sum%2==0){
		for(int i=1;i<=sum/2;i++){
			if(cc[i]!=cc[sum-i])ans++;
		}
	}
	else{
		for(int i=1;i<=sum/2;i++){
			if(cc[i]!=cc[sum-i+1])ans++;
		}
	}
	cout << ans;
	
	return 0;
} 
