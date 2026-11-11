#include<bits/stdc++.h> 
using namespace std;


//long long a[200010];

//int erfen(int l, int r, long long goal){
//	int ans;
//	while(l <= r){
//		int now = (l + r)/2;
//		if(a[now] <= goal){
//			r = now;
//			ans = now;
//		}else if(a[now] > goal){
//			l = now - 1;
//		}
//		return ans;
//	}
//	
//}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n, cnt = 0, l = 0;
	string s = "0";
	scanf("%d", &n);
//	a[0] = 0;
	for(int i = 1; i <= n; i ++){
//		scanf("%d %c",&a[i],&s[i]);
//		a[i] += a[i - 1];
        int a;
        char c;
        scanf("%d %c",&a,&c);
        for(int j = 0; j < a; j ++)
		s += c;
		l += a;
	}
//	f();or(long long i = 1; i <= l/2; i ++){
//		long long p = l + 1 - i;
//		cout << erfen(1,n,p) <<endl <<  erfen(1,n,i) << endl;
//		if(s[erfen(1,n,p)] != s[erfen(1,n,i)]){
//		    cnt ++ ;	
//		}
//	}
    for(int i = 1; i <= (l + 1)/2; i ++){
    	if(s[i] != s[l + 1 - i ]){
    		cout << i << endl;
    		cnt ++;
		}
	}
	printf("%d",cnt);	
	return 0;
}


//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
//Trick||Treat!
