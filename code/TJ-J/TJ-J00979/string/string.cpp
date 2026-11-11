#include <bits/stdc++.h>
using namespace std;
int n;
long long a1[200010];
char a2[200010];
//char s1[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
//'p','q','r','s','t','u','v','w','x','y','z'};
long long s2[26];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a1[i] >> a2[i];
    }
	long long sum = 0;
	for(int i = 0; i < n; i++){
		sum=sum+a1[i];
	}
	long long sum2 = sum;
	if(sum%2==1){
		int sum1 = sum/2+1;
		sum=0;
	    for(int i = 0; i < n; i++){
	    	if(sum+a1[i]<sum1){
	    		sum=sum+a1[i];
			}else{
				a1[n] = sum+a1[i]-sum1;
				a2[n] = a2[i];
				a1[i] = sum1-sum-1;
				break;
			}
		}
		int max1 = INT_MIN;
		for(int i = 0; i < n+1; i++){
			int idx = a2[i]-97;
			s2[idx]+=a1[i];
			if(max1<s2[idx]) max1=s2[idx];
			//max1 = max(max1,s2[idx]);
		}
		cout << sum2-1-max1;
	}
	else{
		int sum1 = sum/2;
//		sum=0;
//	    for(int i = 0; i < n; i++){
//	    	if(sum+a1[i]<sum1){
//	    		sum=sum+a1[i];
//			}else{
//				a1[n] = sum+a1[i]-sum1;
//				a2[n] = a2[i];
//				a1[i] = sum1-sum-1;
//				break;
//			}
//		}
		long long max1 = INT_MIN;
		for(int i = 0; i < n; i++){
			int idx = a2[i]-97;
			s2[idx]+=a1[i];
			//max1 = max(max1,s2[idx]);
			if(max1<s2[idx]) max1=s2[idx];
//			cout << s2[idx] << " " << max1 << endl;
		}
		cout << sum2-max1;
	}
	
	
	
	
	
	
	return 0;
}
