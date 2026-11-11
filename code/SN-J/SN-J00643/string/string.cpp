//JiangMingrui xian89zhong SN-J00643
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long long n,m=0;
	cin >> n;
	long long a[n+5];
	string c[n+5];
	string S="";
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cin >> c[i];
		for(int zxc=0;zxc<a[i];zxc++)
		S+=c[i];
	}


	if(S.size()%2==0){
		for(int qwe=0;qwe<S.size()/2;qwe++){
			if(S[qwe]!=S[S.size()-qwe-1])
			m+=1;
		}
	}
	else{
		for (int asd=0;asd<S.size()/2;asd++){
			if(S[asd]!=S[S.size()-asd-1])
			m+=1;
		}
	}
	cout << m;
	return 0;
}
