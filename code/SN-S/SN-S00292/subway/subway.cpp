#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
struct Sub{
	int w;
	int t[25];
};
Sub s[500005];
int chuxing(){
	int begin,end;cin >> begin >> end;
	int ans = s[begin].w + s[end].w;
	while(1){
		int x=1e8,y=1e8,xx=begin,yy=end;
		for(int i = 1;i<=n;i++){
			if(s[begin].t[i]!=0 && s[end].t[i]!=0){
				ans+=s[begin].t[i] + s[end].t[i];
				return ans;
			}
			if(s[begin].t[i]!=0){
				x = min(s[begin].t[i],x);
				xx=i;
			}
			if(s[end].t[i]!=0){
				y = min(s[end].t[i],y);
				yy = i;
			}
		}
		begin = xx;
		end = yy;
		
	}
	return 0;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >>m >> d >> q;
	for(int i =1;i<=m;i++){
		cin>> s[i].w;
	}
	for(int i =1;i<=n; i++){
		int k;cin >> k;
		for(int j = 1; j<=k; j++){
			int x,y;cin >> x >>y;
			s[x].t[i] = y;
		}
		
	}



	for(int i =1;i<=q; i++){
		cout << chuxing()<<endl;
	}

	return 0;
}
