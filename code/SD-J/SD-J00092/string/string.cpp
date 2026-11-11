#include<iostream>
#define int long long
using namespace std;
int n,a[200010],len,cnt;
char c[200010];
string s="@";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		len+=a[i];
		for(int j=1;j<=a[i];++j){
			s+=c[i];
		}
	}
	int l=1,r=len;
	while(l<=r){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
/*


^q^ 
32356235123235636875232356235123235636875 35873569735873589653876569753678975587536
656789877535659#8955568753 66563535877565635358773666565656663538736663635877566656

63213887568987585232363337333123569#989#9735656
65323212365335323212365689#99#9865653235656


*/
