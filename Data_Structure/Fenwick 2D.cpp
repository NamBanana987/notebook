const int N = 1e3+5;
int fen[N][N];


void get(int X, int Y)  {
    int res =0;
    for(int x = X; x>0 ; x-= x&-x) {
        for(int y = Y; y>0; y-=y&-y) {
            res += fen[x][y];
        }
    }
    return res;
}


void update(int X, int Y, int val) {
    for(int x = X; x<N ; x+= x&-x) {
        for(int y = Y; y <N; y+=y&-y) {
            fen[x][y] += val;;
        }
    }
}
