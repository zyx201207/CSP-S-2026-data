 #include<bits/stdc++.h>
 using namespace std;
 int a[200001];
 char c[200001];
 char s1[100000001];
 char s2[100000001];
 int main(){
 	int n,ans = 0,f = 0;
 	cin >> n;
 	for(int i = 1;i <= n;i++){
 		cin >> a[i] >> c[i];
	}
	for(int q = 1;q <= n;q++){
		for(int i = 1;i <= a[q];i++){
			s1[i+ans] = c[q];
		}
		ans += a[q];
	}
	for(int i = ans;i >= 1;i--){
		s2[ans-i+1] = s1[i];
	}
	for(int i = 1;i <= ans;i++){
		if(s1[i] != s2[i]){
			f++;
		}
	}
	f/=2;
	cout << f;
 	return 0;
 }
