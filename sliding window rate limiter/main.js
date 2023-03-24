class SlidingWindow{
    constructor(windowSize, limit) {
        this.windowSize = windowSize;
        this.limit = limit;
        this.count = new Array(windowSize).fill(0);
        this.index = 0;
    }

    allowRequest() {
        const now = Math.floor(Date.now() / 1000);
        const currIndex = now % this.windowSize;
        this.count[currIndex]++;

        const sum = this.count.reduce((a, b) => { a + b });
        if (sum > this.limit) {
            console.log("Request not completed");
            return false;
        }

        //completion of request 

        const oldIndex = (this.index + 1) % this.windowSize;
        this.count[oldIndex]--;
        this.index = oldIndex;
        return true;
        
    }

}

const window = new SlidingWindow(1, 1);

for (let i = 0; i < 100000; i++){
    window.allowRequest();
}