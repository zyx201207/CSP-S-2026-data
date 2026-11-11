#include<iostream>
const int N = 2e5+10;
#define ull unsigned long long
int n;
ull a[N],l[N],len,len_tmp,tot,ans;char c,cs[N];
ull min(ull a,ull b){
	return a<b?a:b;
}
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::cin >> n;
	for(int i = 1;i <= n;i++){
		std::cin >> len_tmp >> c;
		if(c != cs[tot]){
			a[++tot] = len + 1;
			l[tot] = len_tmp;
			cs[tot] = c;
		}else{
//			std::cout << "ºÏ²¢£¡£¡" <<std:: endl;
			l[tot] += len_tmp;
		}
		len += len_tmp;
	}
	int i = 1,j = tot;
	while(true){
//		printf("%d:%d %d:%d",i,l[i],j,l[j]);
		if(cs[i] != cs[j]) ans += min(l[i],l[j]);
		if(l[i] < l[j]) l[j] -= l[i],i++;
		else if(l[i] > l[j]) a[i] += l[j],l[i] -= l[j],j--;
		else i++,j--;
		if(i >= j) break;
	}
	std::cout << ans;
	return 0;
}
