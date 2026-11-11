#include<bits/stdc++.h>
using namespace std;


struct op{
    long long start;
    long long num;
    char c;
};

long long n,a,ind = 0;
long long l = 0;
vector<op> p;
char b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        op tmp = {ind,a,b};
        p.push_back(tmp);
        ind+=a;
        l+=a;
    }
    //cout << ys <<endl;
    long long now_l = 0;
    long long now_r = n-1;
    long long c = l - (l % 2);
    long long chance = 0;
    while(now_r > now_l){
        if(p[now_l].num > p[now_r].num){
            if(p[now_l].c != p[now_r].c) chance += p[now_r].num;
            p[now_l].num-=p[now_r].num;
            now_r--;
        }else if(p[now_l].num < p[now_r].num){
            if(p[now_l].c != p[now_r].c) chance += p[now_l].num;
            p[now_r].num-=p[now_l].num;
            now_l++;
        }else{
            if(p[now_l].c != p[now_r].c) chance += p[now_r].num;
            now_l++;
            now_r--;
        }
        //cout<<chance<<endl;
        //cout<<now_l<<" "<<now_r<<endl;
    }
    cout<<chance<<endl;


    fclose(stdin);
    fclose(stdout);
    return 0;
}
