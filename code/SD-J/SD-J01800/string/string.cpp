#include <bits/stdc++.h> 
using namespace std;

long long n,i,j,A[200010],len = 0,mid,ans = 0;
char C[200010];
string str = "";

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	 
	int flag = 0;
	
	cin>>n;
	for(i = 1;i <= n;i++){
		cin>>A[i]>>C[i];
		if(i > 1 && C[i] == C[i - 1]) flag++;
	}
	if(flag+1 == n){ 
		cout<<0;
		return 0;
	}
	
	int f1,f2;
	
	for(i = 1;i <= n / 2;i++){
		int t = n + 1 - i;
		if(A[i] == A[t]){
			if(C[i] == C[t]){
				continue;  
			}
			ans += A[i];
		}
		else{
			if(A[i] > A[t]){
				A[i] -= A[t];
				if(C[i] != C[t]) ans += A[t];
				A[t] = 0;
				f1 = i;
				f2 = t - 1;
			}
			else{
				A[t] -= A[i];
				if(C[i] != C[t]) ans += A[i];
				A[i] = 0;
				f1 = i + 1;
				f2 = t;
			}
			break;
		}
	}
		
	for(int i = f1;i <= f2;i++){
		int cnt = A[i];
		char c = C[i];
		for(j = 1;j <= cnt;j++){
			str += c;
		}
	}

	len = str.size();
	mid = len / 2;
	for(int i = 0;i <= mid - 1;i++){
		if(str[i] != str[len - 1 - i]){
			ans++;	
		}
	}
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
