function browserHistory(){
    this.index = -1;
    this.history = [];

    this.visit = function (url) {
        this.history[++this.index] = url;
        this.history.length = this.index + 1;
    }

    this.current = function () {
        if (this.index < 0) {
            return "Blank page";
        }

        return this.history[this.index];
    }
    
    this.backward = function () {
        this.index = Math.max(-1, --this.index);
    }
    this.forward = function () {
        this.index = Math.min(this.history.length - 1, ++this.index);
    }
}

let bh = new browserHistory();

bh.visit("A");
bh.visit("B");
bh.visit("C");

bh.backward();
bh.backward();
bh.backward();
bh.backward();
bh.forward();

console.log(bh.current());