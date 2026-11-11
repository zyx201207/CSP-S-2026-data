#include<bits/stdc++.h>
using namespace std;
//1000MB => 262144000 int => 131072000 long long
long long a1[500010],a[500010],m;
int i,j,n,ans=1;
int amn = 0;

//ll: 129571870
bool cmp(long long aa,long long bb){
	return aa <= bb;
}
int f(int x){
	return x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	/*ans:3
		  4
		  3845
		  315275
	
	*/
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	
	//O(n)
	for(i = 0;i < n;i++){
		cin >> a1[i];
	}
	//int p1 = amn;//p1 -> head p2 -> tail
	sort(a1,a1+n,cmp);//O(n logn)
	for(i = 0;i < n-1;i++){//O(n)
	    //DEBUG
	    //cout << a1[i] << " ";
	    //g
	    a[i] = a1[i+1]-a1[i];
//		if(a[amn] > a[i]){
//			amn = i;
//			cout << "set" << i << endl;
//		}
	}
	for(i = 0;i < n-1;i++){//O(n)
	    //DEBUG
	    //cout << a1[i] << " ";
	    //g
	    a[i] = a[i+1]-a[i];
		if(a[amn] > a[i]){
			amn = i;
			//cout << "set" << i << endl;
		}
	}
	a[n-1] = a1[n-1];
	if(a[amn] > a[n-1]){
		amn = n-1;
	}
	//DEBUG
//	cout << a1[n-1] << " m "<<a[amn]<< endl;
//	for(i = 0;i < n;i++){
//		cout << a[i] << " ";
//	}
//	cout<<endl;
//	for(i = 0;i < n;i++){
//		cout << a1[i] << " ";
//	}
//	cout<<endl;
	
	int l = amn,r = amn;
	while(true){
		if(l >= 1 && (a[l-1] < a[r] || abs(a1[r]-a1[amn]) > m) && abs(a1[amn]-a1[l-1]) <= m){
			m -= abs(a1[amn]-a1[l-1]);
			a1[l-1] = a1[amn];
			//cout << "full:" << a1[l-1] << " " << l-1 << endl;
			l--;
			ans++;
		}else if(r <= n-2 && (a[r] < a[l-1] || abs(a1[amn]-a1[l-1]) <= m) && abs(a1[r]-a1[amn]) <= m){
			m -= abs(a1[r+1]-a1[amn]);
			a1[r+1] = a1[amn];
			//cout << "full:" << a1[l-1] <<" "<<r+1<< endl;
			r++;
			ans++;
		}else{
			break;
		}
	}
	cout << ans;
	return 0;
} 
