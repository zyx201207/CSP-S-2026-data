#include<bits/stdc++.h>
using namespace std;
int n;
bool o = 1;
long long a[200001],sum,ans;
string s[200010],t[200001];
long long b[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		sum += a[i];
		cin >> s[i];
	}
	sum = (sum + 1) / 2;
	int top = 0,z = a[1];
	b[++top] = a[1];
	t[top] = s[1];
	for(int i = 2;i <= n;i++){
		if(s[i] == s[i - 1] && z + a[i] <= sum){
		   b[top] += a[i];
		}else{
		   if(z + a[i] > sum && o){
		   	  if(s[i] == s[i - 1]){
		   	  	 b[top] += sum - z;	
			  }else{
			  	 b[++top] += sum - z;
			  	 t[top] = s[i];
			  }
			  b[++top] = a[i] - (sum - z);
			  t[top] = s[i];
			  o = 0;
		   }else{
		   	  b[++top] = a[i];
		   	  t[top] = s[i];
		   }
		}
		z += a[i];
	}
//	for(int i = 1;i <= top;i++)
	 //   printf("%d ",b[i]);
	long long p = 1,q = top,l = 0;
	while(l < sum && p < q){
		  while(b[q] <= b[p] && p < q){
		   	    if(t[p] != t[q])
		   	       ans += b[q];
		   	    b[p] -= b[q];
		   	    l += b[q];
		   	    q--;
		   }
		   if(p >= q)
		      break;
		   if(t[p] != t[q])
		      ans += b[p];
		   b[q] -= b[p];
		   l += b[p];
		   p++;
	}
	printf("%lld",ans);
	return 0;
}
