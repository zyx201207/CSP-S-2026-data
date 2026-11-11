#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define lint long long
#define line inline
#define int long long

namespace OIfast{
	#define endl putchar('\n')

	line lint read(){
		lint x=0;int f=1;char c=getchar();
		while(c<'0' or c>'9'){if(c=='-')f=-1;c=getchar();}
		while(c>='0' and c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
		return x*f;
	}

	line void wte(lint x){
		static int sta[40],top=0;
		if(x<0) putchar('-'),x=-x;
		do{sta[++top]=x%10;x/=10;}while(x);
		while(top) putchar(sta[top--]+48);
		return putchar(' '),void();
	}
}using namespace OIfast;

/*
 神秘 t1 要求最多能凑出个相同的 a
 考虑对 a 排序后二分 check 显然 t1 秒了 ??
*/

const int N=5e5+5;
int n,m,a[N],b[N];

line bool check(int l,int r){
    int res=b[r]-b[l-1];
    int cmp=(r-l+1)*a[r];
    int delt=cmp-res;
//    cout<<"mid = "<<l<<" r = "<<r<<"\n";
//    cout<<"res = "<<res<<" cmp = "<<cmp<<" delt = "<<delt<<"\n\n";
    return (delt<=m)?(true):(false);
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
    n=read(),m=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i){
        b[i]=b[i-1]+a[i];
    }

    int ans=0;
    for(int r=1;r<=n;++r){// 枚举右端点
        int l=r,L=1,R=r;// 二分左端点
        while(L<=R){
//       		cout<<"Check : i = "<<r<<" l = "<<l<<" r = "<<r<<"\n";
            int mid=L+R>>1;
            if(check(mid,r)){
                l=mid;
                R=mid-1;
            }
            else{
                L=mid+1;
            }
        }
        ans=max(ans,r-l+1);
        
    }
//    cout<<"     ans = ";
    wte(ans),endl;
    return 0;
}
/*
5 8
-3 -1 2 2 7
output:
4
*/
/*
5 5
1 2 4 8 9
output:
3
*/