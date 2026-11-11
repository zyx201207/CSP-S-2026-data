#include<bits/stdc++.h> 
#include<cstdio>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,su;
	char c;
	long long sum=0,cnt=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%d",&su);
		cin >> c;
		sum+=su;
		for(int j=1;j<=su;j++){
			s+=c;
		}
	}
	long long mid;
		mid=sum/2;
		for(long long i=0;i<mid;i++){
			if(s[i]!=s[sum-i-1]){
				cnt++;
			}
		}
		printf("%d",cnt);
	return 0;
}
