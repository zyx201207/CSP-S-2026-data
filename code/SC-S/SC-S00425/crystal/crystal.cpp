#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],b[500010];

int check(int l,int r){
	long long ans=0;
	ans=b[r]-b[l];
	ans-=(l-1)*(a[r]-a[l]);
	return ans;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int r=(1+n)/2;
	int mid=r/2;
	while(mid){
		if(check(1,r)>m){
			r-=mid;
		}
		else if(check(1,r)==m){
			while(check(1,r)<=m){
				r++;
			}
			cout<<r-1;
			return 0;
		}
		else{
			r+=mid;
		}
		mid/=2;
	}
	while(check(1,r)>m){
		r--;
	}
	while(check(1,r)<=m){
		r++;
	}
	int l=1;
	while(check(l,r)>m&&l<r){
		l++;
	}
	if(check(l,r)>m){
		cout<<r-1;
	}
	else{
		cout<<r-l+1;
	}
	return 0;
}
/*這是我最後一次參加CSP了 
想說說自己的感想（CCF你們查重的時候應該看不到吧） 
上午J組挺簡單應該分數線挺高
下午的S組很難偏分都沒思路
在信奧這條路上也走了挺久了一直沒什麼成績
所以要去中考了
現在這門競賽的環境來看
我初三才學到線段樹（甚至沒怎麼懂）算大齡剩男了
J組給個一等獎安慰下我吧
我還記得第一次打CSP初賽沒過用了學校的保送名額進了J組複賽
結果發現有個叫freopen的東西從來沒聽過
還是旁邊的不認識同學告訴我的
我一開始學信奧是為了以後可以自己做遊戲給自己耍
後來也確實做了文字版的惡魔輪盤 
只能說我其實從頭到尾認真學競賽可能也就一年半 
這樣的結局也配得上我的表現
打完今年就要退役了 
祝我考上七中
希望以後能當遊戲設計師和C++再續良緣（以後編程都是AI乾了吧） 
再見CCF
再見CSP
再見洛谷
我亦將止步於此
*/