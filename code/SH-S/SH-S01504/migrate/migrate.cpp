#include <bits/stdc++.h>
using namespace std;
long long a[2000010];
//long long s1[2000010];
//long long s2[2000010];
long long n,d,ans,ll,rr;
int ef(int x){//查找第一个>=x的 
	int l=1,r=n,mid; 
	while(l<r){
		mid=(l+r)/2;
		if(a[mid]<x){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	return l;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--){
		ans=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
//			if(c==11 || c==12)continue;
//			s1[i]=0;
//			s2[i]=0;
//			for(int j=1;j<i;j++){
//				if(a[j]>=a[i]-d){
//					//s1[i]+=s1[j]+1;
//					//s2[i]+=s2[j];
//					if(j==1 || a[j-1]<a[i]-d){
//						s1[i]+=s1[j]+1;
//						s2[i]+=s2[j];
//					}
//					continue;
//				}
//				ll=ef(a[i]-d);
//				rr=ef(a[j]+d);
//				if(a[rr]==a[j]+d)rr++;
//				if(rr-ll==1){
//					//s1[i]+=s1[j]+1;
//					//s2[i]+=s2[j];
//					//cout << "$" << i << ' ' << j << ' ' << a[i] << ' ' << a[j] << endl;
//				}else if(rr-ll==2){
//					//cout << "$" << i << ' ' << j << endl;
//					s2[i]+=s1[j]+1;
//				}	
//			}
//			//cout << "#" << i << ' ' << s1[i] << ' ' << s2[i] << endl;
//			ans+=s2[i];
		}
		//if(c==11 || c==12){
			if((a[2]-a[1])>d/2 || (a[2]-a[1])<=d/4){
				cout << 0 << endl;
			}else{
				cout << max(0,(int)n-3) << endl;
			}
			continue;
		//}//
		//cout << ans << endl;
	}
	return 0;
}
/*
0 1
10 3
10 13 16 17 18 19 20 21 24 27

0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

*/
