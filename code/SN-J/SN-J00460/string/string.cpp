#inclue <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,c,n,L;
	string s,ans;	cin >> n >> c >> a >> L;

	char a[100000];                                                                             
	scarf("%d",/n);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(s[i]=s[L]+L-i){
			string L;
			i++;
		}
		else if (a[i]=c[i]){
			cout << min(ans,a);
			i++;
		}	
		else if(a[i]!=c[i]){
			cout << a[i]+c[i];
		}
		else{
			countine;
		}
	}
	cout << a;
	return 0;
}
