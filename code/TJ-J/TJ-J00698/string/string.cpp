#include<bits/stdc++.h>
using namespace std;
int n;
const int N=200010;
long long a[N];
char s[N];
long long opt=0,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		if(s[i]<='Z')
			s[i]=s[i]-'A'+'a';
		opt+=a[i];
	}
	while(n>1){
		if(s[0]==s[n-1]){
			long long  c=max(a[0],a[n-1]),v=min(a[0],a[n-1]);
			a[0]-=c-v;
			n--;
		}else{
			
			s[n-1]=s[0];
			long long c=max(a[0],a[n-1]),v=min(a[0],a[n-1]);
			cnt+=v;
			a[0]-=c-v;
			n--;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

