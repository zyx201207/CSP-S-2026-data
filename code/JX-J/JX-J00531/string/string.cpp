#include<iostream>
using namespace std;
int n_str[200005];
int p_str[200005];
char c_str[200005];
int n;

int translate(int f,int l,int a,int b){
    int s = 0;
    if(c_str[a] == c_str[b]){
        if(a = b - 1){
            return 0;
        }
        if(p_str[a] - f < l - p_str[b]){
            l -= p_str[a] - f;
            f = p_str[a];
            a += 1;
        }else{
            f += l - p_str[b];
            l = p_str[b];
            b -= 1;
        }
    }else{
        if(a = b - 1){
            return min(p_str[a] - f,l - p_str[b]);
        }
        if(p_str[a] - f < l - p_str[b]){
            s += p_str[a] - f;
            l -= p_str[a] - f;
            f = p_str[a];
            a += 1;
        }else{
            s += l - p_str[b];
            f += l - p_str[b];
            l = p_str[b];
            b -= 1;
        }
    }
    return translate(f,l,a,b) + s;
}

int main(){
    freopen("string1.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    int last = 0;
    for(int i = 0;i < n;i++){
        cin >> n_str[i];
        cin >> c_str[i];
        last += n_str[i];
    }
    int cl;
    for(int i = 0;i < n;i++){
        cl += n_str[i];
        p_str[i] = cl;
    }
    cout << translate(0,last,0,n - 1);
    return 0;
}
