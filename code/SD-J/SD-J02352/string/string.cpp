#include<iostream> 
#include<cstring>

using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	
	cin>>n;
	
	string S;
	long long wer=0;
		
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		
		cin>>a>>c;
		
		string b;
		
		while(a--){
			b+=c;
		}
		
		S+=b;
	}
	
	long long L=S.length() ;
	
	if(L%2==0){
		for(long long i=0;i<(L+1)/2;i++){	
		if(S[i]!=S[L+1-i]){
			wer++;
			S[L+1-i]=S[i];
		}
		}
	}else{
		for(long long i=0;i<(L-1)/2;i++){	
		if(S[i]!=S[L-1-i]){
			wer++;
			S[L-1-i]=S[i];
		}
		}
	}
	
	cout<<wer;
	return 0;
}
