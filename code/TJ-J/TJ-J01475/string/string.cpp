#include<bits/stdc++.h>
using namespace std;
#define int long long
int n , sum , ans ;
struct Node{
	int a ;
	char c ;
}arr[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	if(n==1){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&arr[i].a,&arr[i].c);
		sum+=arr[i].a;
	}
	int tmp=0 , x , y ;
	for(int i=1;i<=n;i++){
		// cout << "!!!" ;
		if(tmp+arr[i].a>=(sum+1)/2){
			if(sum%2){
				x=(sum+1)/2-tmp-1;
				y=tmp+arr[i].a-(sum+1)/2;
			}else{
				x=(sum+1)/2-tmp;
				y=tmp+arr[i].a-(sum+1)/2;
			}
			tmp=i;
			break;
		}
		tmp+=arr[i].a;
	}
	// cout << tmp << " " << x << " " << y << "\n" ;
	int l , r , sx=sum/2 , sy=sum/2 ;
	l=r=tmp;
	if(x==0)l--,x=arr[l].a;
	if(y==0)r++,y=arr[r].a;
	while(sx>0||sy>0){
		if(arr[l].c==arr[r].c){
			if(x<y)sx-=x,sy-=x,y-=x,x=arr[--l].a;
			else if(x>y)sx-=y,sy-=y,x-=y,y=arr[++r].a;
			else sx-=x,sy-=y,x=arr[--l].a,y=arr[++r].a;
		}else{
			ans+=min(x,y);
			if(x<y)sx-=x,sy-=x,y-=x,x=arr[--l].a;
			else if(x>y)sx-=y,sy-=y,x-=y,y=arr[++r].a;
			else sx-=x,sy-=y,x=arr[--l].a,y=arr[++r].a;
		}
	}
	printf("%lld",ans);
	return 0;
}