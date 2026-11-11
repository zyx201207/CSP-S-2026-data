#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
string now;
long long a[N],s[N],ans,len;
//int L[N],R[N];
char c[N];
//bool check(int now,int pos){
//	if((len-s[now-1]>=s[pos]) && (len-s[now-1]<=s[pos+1]))
//		return 1;
//	else
//		return 0;
//}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		len+=a[i];
		for(int j=1;j<=a[i];j++)
			now+=c[i];
//		s[i]=s[i-1]+a[i];
	}
	for(int i=0;i<=len/2;i++)
		ans+=(now[i]!=now[len-i-1]);
//	for(int i=1;i<=n;i++){
//		L[i]=len-s[i-1];
//		R[i]=len+1-s[i];
//	}
//	for(int i=1;i<=n/2;i++){
//		int posL=1,posR=n,posans=0;
//		while(L<=R){
//			int mid=(posL+posR)>>1;
//			if(check(i,mid)){
//				posans=mid;
//				break;
//			}
//			if(len-s[i-1]>=s[mid] && len-s[i-1]>=s[mid+1])
//				posL=mid+1;
//			else
//				posR=mid-1;
//		}
//		char ch;
//		int pos=len-s[i-1];
//		if(pos>s[posans])
//			ch=c[posans+1];
//		else
//			ch=c[posans];
//		if(a[i]!=ch){
//			ans+=a[posans];
//		}
//	}
	printf("%lld",ans);
	return 0;
}
/*
#1
3
2 a
2 b
1 c
#2
2
2 a
3 a
#3
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
